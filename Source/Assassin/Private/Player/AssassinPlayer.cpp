// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AssassinPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <Components/ArrowComponent.h>

// Sets default values
AAssassinPlayer::AAssassinPlayer()
{
 	// Set this character to call Tick() every frame.  
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 90.0f);

	// ĳ���� �޽� ����
	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -87), FRotator(0, -90, 0));

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	// Character moves in the direction of input...	
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	// ...at this rotation rate
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); 
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->SocketOffset = FVector(0, 0, 50);
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// ���� ���� ��ֹ� ���� ������Ʈ
	ableToJumpOverHeights = CreateDefaultSubobject<UArrowComponent>(TEXT("ableToJumpOverHeights"));
	ableToJumpOverHeights->SetupAttachment(RootComponent);
	// �ַο��� ��ġ ���̰��� ĳ���Ͱ� ���� �� �ִ� ��ֹ� ���� ���� ��
	ableToJumpOverHeights->SetRelativeLocation(FVector(0, 0, -40));
	// �Ŵ޸� ���� �¿��̵� �ַο�
	hangingMoveArrowL = CreateDefaultSubobject<UArrowComponent>(TEXT("hangingMoveArrowL"));
	hangingMoveArrowL->SetupAttachment(RootComponent);
	hangingMoveArrowL->SetRelativeLocation(FVector(15, -45, 100));	
	hangingMoveArrowR = CreateDefaultSubobject<UArrowComponent>(TEXT("hangingMoveArrowR"));
	hangingMoveArrowR->SetupAttachment(RootComponent);
	hangingMoveArrowR->SetRelativeLocation(FVector(15, 45, 100));
	// ���� ���� �̵� �ַο�
	leftLedgeArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("leftLedgeArrow"));
	leftLedgeArrow->SetupAttachment(RootComponent);
	leftLedgeArrow->SetRelativeLocation(FVector(50, -150, 40));	
	rightLedgeArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("rightLedgeArrow"));
	rightLedgeArrow->SetupAttachment(RootComponent);
	rightLedgeArrow->SetRelativeLocation(FVector(50, 150, 40));
	// ��� ���� �̵� �ַο�
	upLedgeArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("upLedgeArrow"));
	upLedgeArrow->SetupAttachment(RootComponent);
	upLedgeArrow->SetRelativeLocation(FVector(0, 0, 130));
	// �ڵ� IK �ַο�
	leftHandIKArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("leftHandIKArrow"));
	leftHandIKArrow->SetupAttachment(RootComponent);
	leftHandIKArrow->SetRelativeLocation(FVector(5, -10, 100));
	rightHandIKArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("rightHandIKArrow"));
	rightHandIKArrow->SetupAttachment(RootComponent);
	rightHandIKArrow->SetRelativeLocation(FVector(5, 10, 100));
	// ǲ IK �ַο�
	leftFootIKArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("leftFootIKArrow"));
	leftFootIKArrow->SetupAttachment(RootComponent);
	leftFootIKArrow->SetRelativeLocation(FVector(10, -15, -40));
	rightFootIKArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("rightFootIKArrow"));
	rightFootIKArrow->SetupAttachment(RootComponent);
	rightFootIKArrow->SetRelativeLocation(FVector(10, 15, -40));
}

// Called when the game starts or when spawned
void AAssassinPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAssassinPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAssassinPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up gameplay key bindings
	check(PlayerInputComponent);
	// PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// �������� ��� Ű ���ε�
	PlayerInputComponent->BindAction("SprintMode", IE_Pressed, this, &AAssassinPlayer::OnActionParkourMode);
	PlayerInputComponent->BindAction("SprintMode", IE_Released, this, &AAssassinPlayer::OnActionReleaseParkourMode);
	// �������� �帧 Ű ���ε�
	PlayerInputComponent->BindAction("DownFlow", IE_Pressed, this, &AAssassinPlayer::OnActionDownFlow);

	// �̵� Ű ���ε� WASD
	PlayerInputComponent->BindAxis("MoveForward", this, &AAssassinPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAssassinPlayer::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void AAssassinPlayer::MoveForward(float Value)
{
	if (!bHangingP)
	{
		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is forward
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get forward vector
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction, Value);
		}
	}
}

void AAssassinPlayer::MoveRight(float Value)
{
	if (!bHangingP)
	{
		if ((Controller != nullptr) && (Value != 0.0f))
		{
			// find out which way is right
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0, Rotation.Yaw, 0);

			// get right vector 
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			// add movement in that direction
			AddMovementInput(Direction, Value);
		}
	}
}

// �������� ��� Ȱ��
void AAssassinPlayer::OnActionParkourMode()
{
	// �������� ��� �ӵ��� ����
	GetCharacterMovement()->MaxWalkSpeed = sprintSpeed;
}

// �������� ��� ��Ȱ��
void AAssassinPlayer::OnActionReleaseParkourMode()
{
	// �Ϲ��̵� ��� �ӵ��� ����
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
}

// �������� ��� - �������� �帧
void AAssassinPlayer::OnActionDownFlow()
{

}


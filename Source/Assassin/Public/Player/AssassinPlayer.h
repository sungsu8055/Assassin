// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AssassinPlayer.generated.h"

UCLASS()
class ASSASSIN_API AAssassinPlayer : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	AAssassinPlayer();
	
// <���� �����>
//===========================================================================================================================================

	// �̵� -------------------------------------------------------------------------------------------
	// �������� ���
	UPROPERTY(EditAnywhere)
	float sprintSpeed = 600;
	// �Ϲ��̵� ���
	UPROPERTY(EditAnywhere)
	float walkSpeed = 170;

	// ���� -----------------------------------------------------------------------------------------
	// ������Ʈ --------------------------------------------------
	// �ѱ� ���� ��ֹ� ���� �ַο�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* ableToJumpOverHeights;
	// ��Ÿ�� �����̵� �ַο�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* hangingMoveArrowL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* hangingMoveArrowR;
	// ���� ���� �̵� �ַο�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftLedgeArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightLedgeArrow;
	// ��� ���� �̵� �ַο�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* upLedgeArrow;
	// IK -------------------------------------------------------------
	// IK ���� �ַο�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftHandIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightHandIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftFootIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightFootIKArrow;
	// Hand IK ��ġ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftHandIK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RightHandIK;
	// foot IK ��ġ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftFootIKloc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector rightFootIKloc;
	// IK ���� bool��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool enableHangingIK;
	// ��ֹ� ��� --------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHitResult rechableLedge;
	// �ּ� �Ÿ� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float distanceToLedge = 20000000000;
	// �̵� ��� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector desiredDir;
	// ���� ���� --------------------------------------------------
	// ���� ��� 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bParkourMode= false;
	// �̵� ���� Ʈ���̽� ��ġ ���� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int inputDirLocMode;
	// ��� �帧 ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUpFlowMode = false;
	// ��Ÿ����ֹ� �ν� Ȯ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbObject = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bjumpOverObject = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bContactObject = false;
	// �� �Ŵ޸� ���� Ȯ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingP = false;
	// ���� �̵� ���� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveRight = false;
	// ���� �̵� ���� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingRight = false;
	// ���� ���� �̵� ���� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpRight = false;
	// ���� ���� �̵� Ȯ�� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumpingLedge = false;
	// ���� �ڳ� �̵� ���� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnRight = false;
	// ���� �ڳ� �̵� �� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurning = false;
	// ��� ���� �̵� ���� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpUp = false;
	// �ڵ��� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurnedBack = false;

	
// <�Լ� �����>
//===========================================================================================================================================
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);
	/** Called for side to side input */
	void MoveRight(float Value);

	// ���ָ�� �Լ�
	void OnActionParkourMode();
	void OnActionReleaseParkourMode();
	// �������� �帧
	void OnActionDownFlow();
	// �ö󰡱� �帧

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

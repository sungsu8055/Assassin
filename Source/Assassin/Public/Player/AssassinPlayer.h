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
	
// <변수 선언부>
//===========================================================================================================================================

	// 이동 -------------------------------------------------------------------------------------------
	// 전력질주 모드
	UPROPERTY(EditAnywhere)
	float sprintSpeed = 600;
	// 일반이동 모드
	UPROPERTY(EditAnywhere)
	float walkSpeed = 170;

	// 파쿠르 -----------------------------------------------------------------------------------------
	// 컴포넌트 --------------------------------------------------
	// 넘기 가능 장애물 높이 애로우
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* ableToJumpOverHeights;
	// 벽타기 측면이동 애로우
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* hangingMoveArrowL;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* hangingMoveArrowR;
	// 측면 점프 이동 애로우
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftLedgeArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightLedgeArrow;
	// 상단 점프 이동 애로우
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* upLedgeArrow;
	// IK -------------------------------------------------------------
	// IK 측정 애로우
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftHandIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightHandIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* leftFootIKArrow;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* rightFootIKArrow;
	// Hand IK 위치값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftHandIK;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector RightHandIK;
	// foot IK 위치값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftFootIKloc;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector rightFootIKloc;
	// IK 실행 bool값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool enableHangingIK;
	// 장애물 어레이 --------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FHitResult rechableLedge;
	// 최소 거리 측정 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float distanceToLedge = 20000000000;
	// 이동 희망 방향
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector desiredDir;
	// 조건 변수 --------------------------------------------------
	// 파쿠르 모드 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bParkourMode= false;
	// 이동 방향 트레이스 위치 세팅 정수값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int inputDirLocMode;
	// 상단 흐름 모드
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUpFlowMode = false;
	// 벽타기장애물 인식 확인 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbObject = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bjumpOverObject = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bContactObject = false;
	// 벽 매달림 상태 확인 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingP = false;
	// 측면 이동 가능 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveRight = false;
	// 측면 이동 진행 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingRight = false;
	// 측면 점프 이동 가능 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpRight = false;
	// 측면 점프 이동 확인 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumpingLedge = false;
	// 측면 코너 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnLeft = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnRight = false;
	// 측면 코너 이동 중 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurning = false;
	// 상단 점프 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpUp = false;
	// 뒤돌기 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurnedBack = false;

	
// <함수 선언부>
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

	// 질주모드 함수
	void OnActionParkourMode();
	void OnActionReleaseParkourMode();
	// 내려가기 흐름
	void OnActionDownFlow();
	// 올라가기 흐름

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

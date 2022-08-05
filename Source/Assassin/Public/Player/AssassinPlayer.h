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
	// 조건 변수 --------------------------------------------------
	// 벽 매달림 상태 확인 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingP;
	// 측면 이동 가능 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMoveRight;
	// 측면 이동 진행 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bMovingRight;
	// 측면 점프 이동 가능 여부 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanJumpRight;
	// 측면 점프 이동 확인 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumpingLedge;
	// 측면 코너 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnLeft;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanTurnRight;

	
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
	void OnActionSprintMode();
	void OnActionReleaseSprintMode();
	// 내려가기 흐름
	void OnActionDownFlow();
	// 올라가기 흐름

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AssassinAnimInst.generated.h"

/**
 * 
 */
UCLASS()
class ASSASSIN_API UAssassinAnimInst : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	// 애님 업데이트 함수 원형
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// 플레이어 캐릭터 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AAssassinPlayer* player;

	// 핸드 IK 위치값
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftHandIKAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector rightHandIKAnim;
	// IK 활성 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableHangingHandIKAnim = false;

	// 점프 중 체크 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;
	// 전진 속도 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float forwardSpeed;
	// 매달림 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingAnim = false;
	// 오르기 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbingAnim = false;
	// 난간 측면 이동 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingRightAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingLeftAnim = false;
	// 난간 측면 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveRightAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveLeftAnim = false;
	// 측면 점프 이동 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpRightLedgeAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpLeftLedgeAnim = false;
	// 상단 점프 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpUpLedgeAnim = false;
	// 뒤돌기 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurnedBackAnim = false;
};

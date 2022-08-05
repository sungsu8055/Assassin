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

	// 점프 중 체크 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;
	// 전진 속도 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float forwardSpeed;
	// 매달림 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingAnim;
	// 오르기 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbingAnim;
	// 난간 측면 이동 상태 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingLeftAnim;
	// 난간 측면 이동 가능 여부 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveLeftAnim;
	// 측면 점프 이동 체크
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpRightLedgeAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpLeftLedgeAnim;
	// 측면 코너 이동 가능 여부 체크

};

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
};

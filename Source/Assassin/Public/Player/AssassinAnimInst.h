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
	// �ִ� ������Ʈ �Լ� ����
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// ���� �� üũ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;
	// ���� �ӵ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float forwardSpeed;
};

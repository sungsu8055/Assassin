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
	// �Ŵ޸� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingAnim;
	// ������ ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbingAnim;
	// ���� ���� �̵� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingLeftAnim;
	// ���� ���� �̵� ���� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveRightAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveLeftAnim;
	// ���� ���� �̵� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpRightLedgeAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpLeftLedgeAnim;
	// ���� �ڳ� �̵� ���� ���� üũ

};

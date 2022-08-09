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

	// �÷��̾� ĳ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AAssassinPlayer* player;

	// �ڵ� IK ��ġ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector leftHandIKAnim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector rightHandIKAnim;
	// IK Ȱ�� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bEnableHangingHandIKAnim = false;

	// ���� �� üũ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsJumping;
	// ���� �ӵ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float forwardSpeed;
	// �Ŵ޸� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHangingAnim = false;
	// ������ ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bClimbingAnim = false;
	// ���� ���� �̵� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingRightAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMovingLeftAnim = false;
	// ���� ���� �̵� ���� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveRightAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLedgeMoveLeftAnim = false;
	// ���� ���� �̵� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpRightLedgeAnim = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpLeftLedgeAnim = false;
	// ��� ���� �̵� ���� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bJumpUpLedgeAnim = false;
	// �ڵ��� ���� üũ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurnedBackAnim = false;
};

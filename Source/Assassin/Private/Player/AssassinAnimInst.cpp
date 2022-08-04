// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AssassinAnimInst.h"
#include "Player/AssassinPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>

void UAssassinAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// ���� ������ ���� �÷��̾� ĳ��Ʈ
	auto player = Cast<AAssassinPlayer>(TryGetPawnOwner());
	if (player) 
	{
		// ĳ���� �����Ʈ �������� ����
		auto playerMove = player->GetCharacterMovement();
		// ���� �� üũ ���� ����
		bIsJumping = playerMove->IsFalling();
		// ���� �ӵ� ���� ����
		forwardSpeed = playerMove->Velocity.Size();
	}
}

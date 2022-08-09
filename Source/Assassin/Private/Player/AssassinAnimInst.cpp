// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AssassinAnimInst.h"
#include "Player/AssassinPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>

void UAssassinAnimInst::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 변수 대입을 위한 플레이어 캐스트
	player = Cast<AAssassinPlayer>(TryGetPawnOwner());
	if (player) 
	{
		// 캐릭터 무브먼트 지역변수 선언
		auto playerMove = player->GetCharacterMovement();
		// 점프 중 체크 변수 대입
		bIsJumping = playerMove->IsFalling();
		// 전진 속도 변수 대입
		forwardSpeed = playerMove->Velocity.Size();

		// 플레이어의 난간 측면 이동 변수와 대입
		// 이동 중
		bLedgeMovingRightAnim = player->bMovingRight;
		bLedgeMovingLeftAnim = player->bMovingLeft;
		// 이동 가능 여부
		bLedgeMoveRightAnim = player->bMoveRight;
		bLedgeMoveLeftAnim = player->bMoveLeft;
	}
}

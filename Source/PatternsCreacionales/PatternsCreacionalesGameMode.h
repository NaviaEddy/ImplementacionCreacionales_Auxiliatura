// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PatternsCreacionalesGameMode.generated.h"

UCLASS(minimalapi)
class APatternsCreacionalesGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APatternsCreacionalesGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class AMusicGameSingleton* MGS;

	class USoundCue* MusicCue;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};




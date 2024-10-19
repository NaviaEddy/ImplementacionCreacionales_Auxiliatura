// Copyright Epic Games, Inc. All Rights Reserved.

#include "PatternsCreacionalesGameMode.h"
#include "PatternsCreacionalesCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MusicGameSingleton.h"
#include "Sound/SoundCue.h"

APatternsCreacionalesGameMode::APatternsCreacionalesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APatternsCreacionalesGameMode::BeginPlay()
{
	Super::BeginPlay();

	MusicCue = LoadObject<USoundCue>(nullptr, TEXT("SoundCue'/Game/Musics/MusicSingleton.MusicSingleton'"));

	for (int i = 0; i <= 4; i++) {
		MGS = GetWorld()->SpawnActor<AMusicGameSingleton>
			(AMusicGameSingleton::StaticClass());
		if (MGS) {
			MGS->Init(MusicCue);
			MGS->PlayMusic();
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Magenta,
				FString::Printf(TEXT("%s se ha creado"), *MGS->GetName()));
		}
	}
}

void APatternsCreacionalesGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MusicGameSingleton.generated.h"

UCLASS()
class PATTERNSCREACIONALES_API AMusicGameSingleton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMusicGameSingleton();

public:

	void Init(USoundCue* _sound);

	void PlayMusic();

	void StopMusic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<AActor*> InstanciasSingleton;

	UPROPERTY()
	AMusicGameSingleton* InstanciaMusic;

	UAudioComponent* AudioMusic;

	USoundCue* SoundCue;

	bool BIsMusicPlaying;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

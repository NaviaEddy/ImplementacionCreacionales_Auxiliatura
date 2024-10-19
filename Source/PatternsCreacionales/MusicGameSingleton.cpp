// Fill out your copyright notice in the Description page of Project Settings.

#include "MusicGameSingleton.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
AMusicGameSingleton::AMusicGameSingleton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Recoge todos los actores del mundo de la clase MusicGameSingleton
	//Y los almacena en el TArray
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), 
		AMusicGameSingleton::StaticClass(), InstanciasSingleton);

	if (InstanciasSingleton.Num() > 1) {
		InstanciaMusic = Cast<AMusicGameSingleton>(InstanciasSingleton[0]);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan,
			FString::Printf(TEXT("%s ya existe, eliminando..."),
				*InstanciaMusic->GetName()));
		Destroy();
	}

	BIsMusicPlaying = false;
	AudioMusic = nullptr;
	SoundCue = nullptr;
}

void AMusicGameSingleton::Init(USoundCue* _sound)
{
	if (_sound) {
		SoundCue = _sound;

		//Obtenenemos los objetos 2d del mundo
		UWorld* World = GetWorld();
		if (World) {
			AudioMusic = UGameplayStatics::SpawnSound2D(World, SoundCue);
			AudioMusic->Stop();
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
				FString::Printf(TEXT("Establecio la musica")));
		}
		else {
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
				FString::Printf(TEXT("No existe el mundo")));
		}
		
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
			FString::Printf(TEXT("No se establecio la musica")));
	}
}

void AMusicGameSingleton::PlayMusic()
{
	if (!BIsMusicPlaying && AudioMusic) {
		AudioMusic->Play();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
			FString::Printf(TEXT("Empezo la musica")));
		BIsMusicPlaying = true;
	}
}

void AMusicGameSingleton::StopMusic()
{
	if (BIsMusicPlaying && AudioMusic) {
		AudioMusic->Stop();
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Emerald,
			FString::Printf(TEXT("Pausando la musica")));
		BIsMusicPlaying = false;
	}
}

// Called when the game starts or when spawned
void AMusicGameSingleton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMusicGameSingleton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


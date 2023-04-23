// Fill out your copyright notice in the Description page of Project Settings.


#include "Subtitles.h"
#include "Engine/EngineTypes.h" 
#include "CompatibilityLayer/Macros.h"
#include "EngineUtils.h" 
#include "SubtitlesFrontend.h"

// Sets default values
ASubtitles::ASubtitles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SubtitlesFrontend= CreateDefaultSubobject<UWidgetComponent>(TEXT("SubtitlesFrontend"));
	SetRootComponent(SpringArm);
	SubtitlesFrontend->AttachToComponent(SpringArm,FAttachmentTransformRules::KeepRelativeTransform);
	SubtitlesFrontend->SetWidgetClass(USubtitlesFrontend::StaticClass());
}

// Called when the game starts or when spawned
void ASubtitles::BeginPlay()
{
	Super::BeginPlay();
	auto a=Cast<USubtitlesFrontend>(SubtitlesFrontend->GetWidget());
	if(a)
	{
		a->GetDelegate()->AddUFunction(this,TEXT("PassSubtitles"));
	}
}

// Called every frame
void ASubtitles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASubtitles::PushSubtitles_Implementation(const TArray<FAdvancedSubtitleCue>& subtitles)
{
	for( auto& subtitle  : subtitles)
	{
		SubtitlesQueue.Push(subtitle);
	}
	if(!isPushingSubtitles)
	{
		isPushingSubtitles= true;
		PassSubtitles();
	}
	//UE_LOG(LogTemp,Warning,TEXT("Test"));
}

void ASubtitles::PassSubtitles_Implementation()
{
	if(SubtitlesQueue.Num()!=0)
	{
		ISubtitleFrontendInterface::Execute_ShowSubtitle(SubtitlesFrontend->GetWidget(),SubtitlesQueue.Pop());
		//	UE_LOG(LogTemp, Warning, TEXT("[%f][%s][%s]: Pass, Num: [%d]"),GetWorld()->TimeSeconds, *GetName(), *FString(__PRETTY_FUNCTION__), SubtitlesQueue.Num());
	}else
	{
		isPushingSubtitles = false;
	}
	
}


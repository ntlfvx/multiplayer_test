// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseTargetActor.h"
#include "Components/BoxComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABaseTargetActor::ABaseTargetActor()
{
	// Turn off tick as not needed
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseTargetActor::OnOverlapBegin); 
}

void ABaseTargetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABaseTargetActor, bBooleanReplicated);
}

void ABaseTargetActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
								UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,
								bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor)
	{
		SetBooleanValue(true);
	}
}

void ABaseTargetActor::SetBooleanValue_Implementation(const bool BooleanReplicated)
{
	bBooleanReplicated = BooleanReplicated;

	OnBooleanValueChanged.Broadcast(bBooleanReplicated);
}
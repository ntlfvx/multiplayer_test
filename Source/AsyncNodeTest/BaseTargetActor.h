// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTargetActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBooleanValueChanged, const bool, NewValue);

UCLASS()
class ASYNCNODETEST_API ABaseTargetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABaseTargetActor();

	UFUNCTION(Server, Reliable)
	void SetBooleanValue(const bool BooleanReplicated);
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
						bool bFromSweep, const FHitResult& SweepResult);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	bool bBooleanReplicated = false;
	
	UPROPERTY(EditAnywhere)
	class UBoxComponent* TriggerBox;

	FBooleanValueChanged OnBooleanValueChanged;
};

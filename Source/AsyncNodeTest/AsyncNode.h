// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsyncNode.generated.h"


class ABaseTargetActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetBooleanValueChanged, const bool, NewValue);

UCLASS()
class ASYNCNODETEST_API UAsyncNode : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", DefaultToSelf = "ListenActor"))
	static UAsyncNode* WaitForBooleanChange(UObject* WorldContextObject, AActor* ListenActor, ABaseTargetActor* TargetActor);

	UFUNCTION()
	void OnBooleanValueChanged(bool NewValue);

	virtual void Activate() override;
	
	UPROPERTY(BlueprintAssignable)
	FOnTargetBooleanValueChanged OnValueChanged;

	UPROPERTY()
	AActor* ListeningActor;

	UPROPERTY()
	ABaseTargetActor* TargetActor;
};
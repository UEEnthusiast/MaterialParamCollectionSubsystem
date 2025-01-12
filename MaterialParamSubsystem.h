// Copyright UEEnthusiast. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MaterialParamSubsystem.generated.h"

namespace MyCore
{
	static const FString ClimateDataAsset = FString{ "/Script/Engine.MaterialParameterCollection'/Game/../Collection/MPC_Exemple.MPC_Exemple" };
} // namespace MyCore

UCLASS(Config=Game)
class UMaterialParamSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditDefaultsOnly)
	FName ScalarParamName = "ScalarName";
};

/**
 * @class UMaterialParamSubsystem
 * @brief A subsystem managing material parameter collection
 */
UCLASS()
class UMaterialParamSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
  	float GetCurrentValueFromMPC() const;
private:
UPROPERTY()
	TObjectPtr<UMaterialParameterCollection> MPCData = nullptr;

	UPROPERTY()
	const UWetnessSubsystemSettings* Settings = nullptr;
};

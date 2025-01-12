// Copyright UEEnthusiast. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "MaterialParamSubsystem.generated.h"

UCLASS(Config=Game)
class UMaterialParamSubsystemSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditDefaultsOnly)
	float GameDuration = 10.f;
};

/**
 * @class UMaterialParamSubsystem
 * @brief A subsystem managing material parameter collection
 */
UCLASS()
class UMaterialParamSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

  float GetCurrentValueFromMPC() const;
};

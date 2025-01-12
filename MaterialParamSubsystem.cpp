// Copyright MaterialParamSubsystem. All rights reserved.

#include "MaterialParamSubsystem.h"

#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"

void UMaterialParamSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Settings = GetDefault<UWetnessSubsystemSettings>();

	if (Settings != nullptr)
	{
		UMaterialParameterCollection* ClimateData = LoadObject<UMaterialParameterCollection>(nullptr, *MyCore::MPCAsset);
	}
}

float UMaterialParamSubsystem::GetCurrentMPCValue() const
{
	UMaterialParameterCollectionInstance* Instance = GetWorld()->GetParameterCollectionInstance(ClimateData);
	if (Instance == nullptr)
	{
		return -1.f;
	}
	
	float Value = 0.f;
	Instance->GetScalarParameterValue(Settings->ScalarParamName, Value);

	return Value;
}

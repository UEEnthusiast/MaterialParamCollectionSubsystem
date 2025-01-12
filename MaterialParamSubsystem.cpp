// Copyright MaterialParamSubsystem. All rights reserved.

#include "MaterialParamSubsystem.h"

#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"

void UMaterialParamSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Settings = GetDefault<UWetnessSubsystemSettings>();
	MPCData = LoadObject<UMaterialParameterCollection>(nullptr, *MyCore::MPCAsset);
}

float UMaterialParamSubsystem::GetCurrentMPCValue() const
{
	if(!ensure(MPCData != nullptr))
	{
		return;
	}
	UMaterialParameterCollectionInstance* Instance = GetWorld()->GetParameterCollectionInstance(MPCData);
	if (Instance == nullptr)
	{
		return -1.f;
	}
	
	float Value = 0.f;
	Instance->GetScalarParameterValue(Settings->ScalarParamName, Value);

	return Value;
}

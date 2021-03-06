/*
Copyright 2016 Krzysztof Lis

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http ://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#pragma once

#include "AURVideoSourceCvCapture.h"
#include "AURVideoSourceCamera.generated.h"

/**
 * Video stream from a camera.
 * Change the settings only before calling Connect
 */
UCLASS(Blueprintable, BlueprintType)
class UAURVideoSourceCamera : public UAURVideoSourceCvCapture
{
	GENERATED_BODY()
	
public:
	// Index (0-based) of the camera to use.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VideoSource)
	int32 CameraIndex;

	// The resolution that will be suggested to the camera
	// (0, 0) means no suggestion will be made
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VideoSource)
	FIntPoint DesiredResolution;

	// Tell the camera whether autofocus should be used
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = VideoSource)
	bool Autofocus;

	UAURVideoSourceCamera();

	virtual FText GetSourceName() const override;
	virtual bool Connect() override;
};
	
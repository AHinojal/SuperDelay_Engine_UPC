#pragma once
#include "Module.h"
#include "../Globals.h"
#include "../Modules/ModuleWindow.h"
#include "../../Libraries/SDL/include/SDL.h"
#include "../../Libraries/MathGeoLib/Geometry/Frustum.h"
#include "../../Libraries/MathGeoLib/Math/float4x4.h"
#include "../../Libraries/MathGeoLib/Math/float3.h"

class ModuleCamera : public Module
{
public:
	ModuleCamera();
	~ModuleCamera();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	//Methods
	float4x4 getProjectionMatrix() { return projectionMatrix; };
	float4x4 getViewMatrix() { return viewMatrix; };
	float4x4 getModelMatrix() { return modelMatrix; };
	float getFOV() { return verticalFOV; };
	float getAspectRadio() { return aspectRadio; };
	float getZNear() { return zNear; };
	float getZFar() { return zFar; };
	Frustum getFrustum() { return frustum; };
	// Setters Window View
	/*void setFOV(float range) {
		horizontalFOV = range;
	}*/
	void setFOVButtons();
	void setAspectRadio() {
		aspectRadio = (float)App->window->width / (float)App->window->height;
	}
	//void setPlaneDistance();
	// Transformations Camera
	// Holding SHIFT duplicates movement speed
	void increaseCameraSpeed();
	void goUpAndDown();
	void zoomForwardAndBackward();
	void moveLeftAndRight();
	void rotatePitch();
	void rotateYaw();
	void rotateRoll();
	void rotatePitchAndYawWithMouse();
	void focusCamera();
	void doRotation(float3x3& rotationMatrix);
	float3 getPosition() { return position; };
	float3 getFront() { return frustum.Front(); };
	float3 getUp() { return frustum.Up(); };

private:
	Frustum frustum;
	float4x4 projectionMatrix;
	float4x4 viewMatrix;
	float4x4 modelMatrix;
	float verticalFOV;
	float aspectRadio;
	float zNear;
	float zFar;
	float3 position, front, up;
	float standardSpeed;
	float actualSpeed;
	float deltaTime;
	float oldTime;
};

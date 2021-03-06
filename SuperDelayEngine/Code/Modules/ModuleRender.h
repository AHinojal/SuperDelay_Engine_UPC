#pragma once
#include "../Modules/Module.h"
#include "../Globals.h"
#include "../../SDL/include/SDL.h"
#include "../../MathGeoLib/Math/float4x4.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void WindowResized(unsigned width, unsigned height);
	inline SDL_GLContext getContext() { return context; };
	inline float4x4 getModelMatrix() { return model; };
	inline float4x4 getViewMatrix() { return view; };
	inline float4x4 getProjectionMatrix() { return projection; };
	inline int getTexture() { return textureRender; };

private:
	// Change type for OpenGL Initialization
	SDL_GLContext context;
	// transforms in camera
	float4x4 model, view, projection;
	// Framebuffer to do a scene window
	unsigned int fbo, rbo;
	unsigned int textureRender;
};

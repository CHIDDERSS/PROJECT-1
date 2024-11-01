// PROJECT-1.cpp: A program using the TL-Engine
#include <iostream>
#include <vector>
#include "TL-Engine11.h" // TL-Engine11 include file and namespace
using namespace tle;

int main()
{
	// Create a 3D engine (using TL11 engine here) and open a window for it
	TLEngine* myEngine = New3DEngine(TL11);
	myEngine->StartWindowed();

	// Add default folder for meshes and other media
	myEngine->AddMediaFolder("C:\\Users\\Public\\Documents\\TL-Engine11\\Media");

	/**** Set up your scene here ****/
	Mesh* cubeMesh;
	Model* cube;
	Mesh* torusMesh;
	Model* torus;
	Mesh* gridMesh;
	Model* grid;

	std::vector<Model*> cubes;

	const int gridSize = 10;
	const float spacing = 20.0f;

	cubeMesh = myEngine->LoadMesh("cube.x ");
	cube = cubeMesh->CreateModel(25.0, 0.0, 0.0);
	/*torusMesh = myEngine->LoadMesh("torus.x");*/
	//torus = torusMesh->CreateModel(20, 0, 10);
	gridMesh = myEngine->LoadMesh("grid.x");
	grid = gridMesh->CreateModel();

	Camera* myCamera;
	myCamera = myEngine->CreateCamera(kFPS);

	for (size_t i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
		{
			Model* cube = cubeMesh->CreateModel(i * spacing, 0.0f, j * spacing);
			cubes.push_back(cube);
		}
	};
	
	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		for (auto& cube : cubes)
		{
			cube->RotateY(0.05f);
			cube->MoveY(0.01f);
		}
		

		/**** Update your scene each frame here ****/


		// Stop if the Escape key is pressed
		if (myEngine->KeyHit(Key_Escape))
		{
			myEngine->Stop();
		}
	}

	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

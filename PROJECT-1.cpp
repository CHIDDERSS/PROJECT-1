//	MERGING UNI WORK WITH THIS WORK
// https://stackoverflow.com/questions/1425892/how-do-you-merge-two-git-repositories


// PROJECT-1.cpp: A program using the TL-Engine
#include <iostream>
#include <vector>
#include "TL-Engine11.h" // TL-Engine11 include file and namespace
using namespace tle;
using namespace std;

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
	Mesh* sphereMesh;
	Model* sphere;

	vector<Model*> cubes;

	int gridSize = 10;		//35 = 1,225 of whatever model in a grid
	float spacing = 20.0f;

	cubeMesh = myEngine->LoadMesh("cube.x ");
	cube;														 // removed CreateModel as it was creating one seperate from the migrating cubes
	/*torusMesh = myEngine->LoadMesh("torus.x");*/
	/*torus = torusMesh->CreateModel(75, 0, 10);*/
	gridMesh = myEngine->LoadMesh("grid.x");
	grid = gridMesh->CreateModel();
	//sphereMesh = myEngine->LoadMesh("sphere.x");
	//sphere = sphereMesh->CreateModel(50, 0, 10);

	Camera* myCamera;
	myCamera = myEngine->CreateCamera(kFPS);

	// if statemnt for when the cubes get to certain height then move a different direction

	for (size_t i = 0; i < gridSize; i++)
	{
		for (int j = 0; j < gridSize; j++)
		{
			Model* cube = cubeMesh->CreateModel(i * spacing, 0.00f, j * spacing);
			cubes.push_back(cube);

		}
	}; 

	// when cubes reach height increase spacing so they disperse 

	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();

		for (auto& cube : cubes)
		{
			cube->RotateY(0.01f);
			cube->MoveY(0.01f);
			if (cube->GetY() > 0.25f)
			{
				
			}
	
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

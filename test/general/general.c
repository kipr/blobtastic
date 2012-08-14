#include <blobtastic/camera.h>

int main(int argc, char* argv[])
{
	if(!camera_open()) {
		printf("Failed to open camera.\n");
		return 1;
	}
	
	camera_update();
	
	printf("Closing camera...\n");
	camera_close();
	
	return 0;
}
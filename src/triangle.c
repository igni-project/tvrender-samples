/* triangle.c - simplest visible TVrender demo */

#include "triangle.h"

#include <libtvrender/tvr.h>
    
#include <stdint.h> 
#include <unistd.h> 

struct vertex
{
	float pos[3];
	float normal[3];
	float texCoord[2];
};
	
struct vertex test_tri_vertices[3] = {
	{{5, 5, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 1.0f}},
	{{5, -5, 0.0f}, {0.0f, 0.0f, 0.0f}, {1.0f, 0.0f}},
	{{-5, 0, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f}}
};	  
uint32_t test_tri_indices[3] = {
	0, 1, 2
};

int main(int argc, char **argv)
{
	int fd;

	uint32_t tex_width;
	uint32_t tex_height;
	uint32_t tex_channels;
	void *tex_data;

	/* Establish a connection with the TVrender server */
	fd = tvr_open();


	tvr_create_vert_buf(
		/* Field 1: the socket to send this request through */
		fd,
		/* Field 2: 22, the unique ID code that the vertex buffer will have */
		22,
		/* Field 3: 3 vertices, the size of the vertex buffer */
		sizeof(struct vertex) * 3,
		/* Field 4: contents of the vertex buffer */
		test_tri_vertices
	);

	tvr_create_index_buf(
		/* Field 1: the socket to send this request through */
		fd,
		/* Field 2: 33, the unique ID code that the index buffer will have */
		33,
		/* Field 3: 3 indices, the size of the index buffer */
		sizeof(uint32_t) * 3,
		/* Field 4: contents of the index buffer */
		test_tri_indices
	);
	
	tvr_create_mesh(
		/* Field 1: the socket to send this request through */
		fd,
		/* Field 2: the ID code of the mesh to be made */
		11,
		/* Field 3: the ID of the mesh's vertex buffer*/
		22,
		/* Field 4: the ID of the mesh's index buffer */
		33
	);

	/* Make the mesh visible by adjusting the scale. */
	tvr_mesh_set_scale(
		/* Field 1: the socket to send this request through */
		fd,
		/* Field 2: the ID code of the mesh to scale */
		11,
		/* Fields 3, 4 and 5: X, Y and Z scale, respectively */
		1, 1, 1
	);

	while (1)
	{
		sleep(1);
	}

	return 0;
}




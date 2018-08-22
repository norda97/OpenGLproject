#include "ObjLoader.h"


Model * loadOBJ(const std::string & path)
{
	std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
	std::vector< glm::vec3 > temp_vertices;
	std::vector< glm::vec2 > temp_uvs;
	std::vector< glm::vec3 > temp_normals;

	Model* finalModel = new Model;

	std::vector<Mesh> meshes;
	std::map<std::string, Material> tempMaterial;
	char mtlString[80];
	
	Mesh* temp = new Mesh();

	bool hasNormals = false;
	bool hasUVs = false;
	bool hasMoreMaterials = false;


	FILE * file = fopen(path.c_str(), "r");
	if (file == NULL) {
		printf("OBJLoader: Can't open the .obj file !\n");
	}


	

	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
		{
			for (unsigned int i = 0; i < vertexIndices.size(); i++)
			{

				vertexStruct vertex;

				unsigned int vertexIndex = vertexIndices[i];
				vertex.position[0] = temp_vertices[vertexIndex - 1][0];
				vertex.position[1] = temp_vertices[vertexIndex - 1][1];
				vertex.position[2] = temp_vertices[vertexIndex - 1][2];

				vertexIndex = normalIndices[i];
				vertex.normals[0] = temp_normals[vertexIndex - 1][0];
				vertex.normals[1] = temp_normals[vertexIndex - 1][1];
				vertex.normals[2] = temp_normals[vertexIndex - 1][2];

				if (hasUVs)
				{
					vertexIndex = uvIndices[i];
					vertex.uv[0] = temp_uvs[vertexIndex - 1][0];
					vertex.uv[1] = temp_uvs[vertexIndex - 1][1];
				}
				else
				{
					vertex.uv[0] = 0.0f;
					vertex.uv[1] = 0.0f;
				}

				temp->addVertex(vertex);
			}
			temp->setMaterial(tempMaterial[mtlString]);
			finalModel->addMesh(temp);
			break; // EOF = End Of File. Quit the loop.
		}
		
		if (strcmp(lineHeader, "#") == 0) {
			fgets(lineHeader, 128, file);
			continue;
		}
		else if (strcmp(lineHeader, "mtllib") == 0) {
			char mtlString[80];
			fscanf(file, "%s", mtlString);

			std::string mtlName(path);
			mtlName = mtlName.substr(0, mtlName.find_last_of("/\\") + 1).append(mtlString);
			tempMaterial = loadMaterial(mtlName);
		}
		else if (strcmp(lineHeader, "v") == 0) {
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineHeader, "vt") == 0) {
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
			hasUVs = true;
		}
		else if (strcmp(lineHeader, "vn") == 0) {
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
			hasNormals = true;
		}
		else if (strcmp(lineHeader, "usemtl") == 0)
		{
			if (hasMoreMaterials)
			{
				for (unsigned int i = 0; i < vertexIndices.size(); i++)
				{

					vertexStruct vertex;

					unsigned int vertexIndex = vertexIndices[i];
					vertex.position[0] = temp_vertices[vertexIndex - 1][0];
					vertex.position[1] = temp_vertices[vertexIndex - 1][1];
					vertex.position[2] = temp_vertices[vertexIndex - 1][2];

					vertexIndex = normalIndices[i];
					vertex.normals[0] = temp_normals[vertexIndex - 1][0];
					vertex.normals[1] = temp_normals[vertexIndex - 1][1];
					vertex.normals[2] = temp_normals[vertexIndex - 1][2];

					if (hasUVs)
					{
						vertexIndex = uvIndices[i];
						vertex.uv[0] = temp_uvs[vertexIndex - 1][0];
						vertex.uv[1] = temp_uvs[vertexIndex - 1][1];
					}
					else
					{
						vertex.uv[0] = 0.0f;
						vertex.uv[1] = 0.0f;
					}

					temp->addVertex(vertex);
				}
				temp->setMaterial(tempMaterial[mtlString]);
				finalModel->addMesh(temp);
			}

			hasMoreMaterials = true;
			fscanf(file, "%s", mtlString);
		}
		else if (strcmp(lineHeader, "f") == 0) {
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

			if(hasNormals && hasUVs)
				fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			else if (!hasUVs && hasNormals)
				fscanf(file, "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]);
			
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);

			if (hasUVs)
			{
				uvIndices.push_back(uvIndex[0]);
				uvIndices.push_back(uvIndex[1]);
				uvIndices.push_back(uvIndex[2]);
			}
			if (hasNormals)
			{
				normalIndices.push_back(normalIndex[0]);
				normalIndices.push_back(normalIndex[1]);
				normalIndices.push_back(normalIndex[2]);
			}
		}
	}
	return finalModel;
}



std::map<std::string, Material> loadMaterial(const std::string & path)
{
	glm::vec3 K;
	float Ns;
	std::map<std::string, Material> mat;
	Material temp;
	unsigned mtlCount = 0;
	char mtlString[80];

	FILE * file = fopen(path.c_str(), "r");
	if (file == NULL) {
		printf("OBJLoader: Can't open the .mtl file !\n");
		return mat;
	}

	while (1) {

		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
		{
			mat.insert(std::make_pair(mtlString, temp));
			break; // EOF = End Of File. Quit the loop.
		}
		
		
		if (strcmp(lineHeader, "#") == 0) {
			fgets(lineHeader, 128, file);
			continue;
		}
		else if (strcmp(lineHeader, "newmtl") == 0) {
					
			if (mtlCount > 0)
			{
				mat.insert(std::make_pair(mtlString, temp));
			}
			fscanf(file, "%s", mtlString);
			mtlCount++;
			continue;
		}
		else if (strcmp(lineHeader, "Ka") == 0)
		{
			fscanf(file, "%f %f %f\n", &K[0], &K[1], &K[2]);
			temp.setKa(K);
		}
		else if(strcmp(lineHeader, "Kd") == 0)
		{
			fscanf(file, "%f %f %f\n", &K[0], &K[1], &K[2]);
			temp.setKd(K);
		}
		else if (strcmp(lineHeader, "Ks") == 0)
		{
			fscanf(file, "%f %f %f\n", &K[0], &K[1], &K[2]);
			temp.setKs(K);
		}
		else if (strcmp(lineHeader, "Ns") == 0)
		{
			fscanf(file, "%f\n", &Ns);
			temp.setNs(Ns);
		}
		else if (strcmp(lineHeader, "d") == 0)
		{
			fscanf(file, "%f\n", &Ns);
			temp.setD(Ns);
		}
	}

	return mat;
}

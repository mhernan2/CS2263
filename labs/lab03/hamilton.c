// author: Mauricio Hernandez 3566371

#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array, int length) {
	int i;
	for (i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}
}

int checkPath(int next, int previous, int *offsets, int *edges) {
	int i;
	for (i = offsets[previous]; i < offsets[previous + 1]; i++) {
		if (edges[i] == next) {
			return 1;
		}
	}
	return 0;
}

int checkHamiltonPath(int vertices, int *seenVertices, int length) {
	int *i, *k, j, missed;
	// check for missed
	for (j = 0; j < vertices; j++) {
		missed = 1;
		for (i = seenVertices; i < seenVertices + length; i++) {
			if (*i == j) {
				missed = 0;
				break;
			}
		}

		if (missed) {
			return 0;
		}
	}

	return 1;
}

int checkRepeated(int *path, int length) {
	int *i, *j;
	for (i = path; i < path+length; i++) {
		for (j = path; j < path+length; j++) {
			if (i != j && *i == *j) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {

	int vertexCount, edgeCount;
	scanf("%d%d", &vertexCount, &edgeCount);

	int path[100], offsets[vertexCount], edges[edgeCount];

	fillArray(offsets, vertexCount + 1);
	fillArray(edges, edgeCount);

	int i = 1, previous, next, isPath = 1, isHamiltonPath = 1;
	scanf("%d", &previous);
	path[0] = previous;

	while (scanf("%d", &next) == 1) {
		if (!checkPath(next, previous, offsets, edges) || checkRepeated(path, i)) {
			isPath = 0;
			break;
		}
		path[i++] = next;
		previous = next;
	}

	isHamiltonPath = isPath ? checkHamiltonPath(vertexCount, path, i) : 0;
	char *pathOptions[] = {"is NOT a path", "is a path"};
	char *hamiltonOptions[] = {"is NOT a Hamiltonian path", "is a Hamiltonian path"};

	printf("%s\n", pathOptions[isPath]);
	printf("%s\n", hamiltonOptions[isHamiltonPath]);

	return 0;
}
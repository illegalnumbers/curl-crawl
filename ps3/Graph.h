#include "Link.h"

using namespace std;

class Graph
{
public:
	Graph(void);
	~Graph(void);

	// Methods

	/**
	* As you traverse the graph, each link is flagged as having been "visited."
	* This method resets the visited status of each link back to the default
	* value of "false."
	*/
	void resetVisitSession();

	/**
	* Overload for the brackets
	*/
	Link operator[] (int i);

	/**
	* Adds a link object to the graph.
	* Does not check to see if it exists already.
	*/
	void addLink(Link link);

	/**
	* Returns the number of link objects the graph contains
	*/
	int getSize();


private:
	vector<Link> links;
	int size;
};


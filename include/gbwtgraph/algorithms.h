#ifndef GBWTGRAPH_ALGORITHMS_H
#define GBWTGRAPH_ALGORITHMS_H

#include <unordered_set>

#include <gbwtgraph/gbwtgraph.h>

/*
  algorithms.h: Various graph algorithms. Some are used internally for building a
  GBWTGraph from another graph, while others take advantage of the CachedGBWT layer.
*/

namespace gbwtgraph
{

//------------------------------------------------------------------------------

/*
  Return the weakly connected components in the graph. The components are sorted by
  the minimum node id, and the node ids in each component are also sorted.
*/
std::vector<std::vector<nid_t>> weakly_connected_components(const HandleGraph& graph);

/*
  Determine whether the given component is acyclic in a nice way. In such graphs,
  when we start from nodes with indegree 0 in forward orientation, we reach each node
  in a single orientation and find no cycles. Return the head nodes when the component
  passes the tests or an empty vector otherwise.
*/
std::vector<nid_t> is_nice_and_acyclic(const HandleGraph& graph, const std::vector<nid_t>& component);

//------------------------------------------------------------------------------

/*
  Return a topological order of handles in the subgraph induced by the given node ids,
  or an empty vector if no such order exists. If the subgraph is small, providing a cache
  may improve speed, especially if the subgraph is further processed using the same cache.
*/
std::vector<handle_t> topological_order(const GBWTGraph& graph, const std::unordered_set<nid_t>& subgraph, gbwt::CachedGBWT* cache = nullptr);

//------------------------------------------------------------------------------

} // namespace gbwtgraph

#endif // GBWTGRAPH_ALGORITHMS_H

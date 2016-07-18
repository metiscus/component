#ifndef src_node_h_
#define src_node_h_

#include <cstdint>
#include "rectangle.h"
#include "transform.h"
#include <memory>
#include <vector>

class Node;
typedef std::shared_ptr<Node> NodePtr;

class Visitor;

class Node
{
private:
    Transform transform_;
    Rectangle bound_;
    std::vector<NodePtr> children_;
    uint32_t layer_;

public:
    Node();

    virtual ~Node();

    void AddChild(NodePtr child);
    void RemoveChild(NodePtr child);
    uint32_t GetNumChildren() const;
    NodePtr GetChild(uint32_t idx);

    const Rectangle& GetBound() const;
    void SetBound(const Rectangle& bound);

    Transform& GetTransform();
    const Transform& GetTransform() const;
    void SetTransform(const Transform& transform);

    inline uint32_t GetLayer() const { return layer_; }
    void SetLayer(const uint32_t& layer);

    virtual void Apply(Visitor& visitor);
};

#endif

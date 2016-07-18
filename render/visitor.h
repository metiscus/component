#pragma once

class Node;
class Sprite;

class Visitor
{
private:

public:
    Visitor();
    virtual ~Visitor();

    virtual void Visit(const Node& node) = 0;
    virtual void Visit(const Sprite& sprite) = 0;

};

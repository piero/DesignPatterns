/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <string>
#include <vector>

namespace perception
{

class Composite
{
public:
    virtual ~Composite();

    virtual size_t size() const = 0;

    virtual bool isLeaf() const = 0;

    virtual void accept(class Visitor& visitor) = 0;

    std::string getName() const;

    virtual class CompositeNode* addNode(const std::string& name) = 0;
    virtual class CompositeLeaf* addLeaf(const std::string& name, const std::string& value) = 0;

    virtual bool has(const std::string& name) const = 0;

protected:
    Composite(const std::string& name);

    std::string _name;
};



class CompositeLeaf : public Composite
{
public:
    CompositeLeaf(const std::string& name, const std::string& value);

    virtual ~CompositeLeaf();

    virtual size_t size() const;

    virtual bool isLeaf() const;

    virtual void accept(class Visitor& visitor);

    virtual CompositeNode* addNode(const std::string& name);
    virtual CompositeLeaf* addLeaf(const std::string& name, const std::string& value);

    virtual bool has(const std::string& name) const;

    std::string getValue() const;

private:
    std::string _value;
};



class CompositeNode: public Composite
{
public:
    CompositeNode(const std::string& name);

    virtual ~CompositeNode();

    virtual size_t size() const;

    virtual bool isLeaf() const;

    virtual void accept(class Visitor& visitor);

    virtual CompositeNode* addNode(const std::string& name);
    virtual CompositeLeaf* addLeaf(const std::string& name, const std::string& value);

    void remove(Composite* node);

    virtual bool has(const std::string& name) const;

private:
    std::vector<Composite*> _nodes;
};

} /* namespace perception */

#endif /* COMPOSITE_H_ */

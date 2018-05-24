template <typename Container>
class readonly_container_facade {
public:
    typedef typename Container::size_type size_type;
    typedef typename Container::const_iterator const_iterator;

    virtual ~readonly_container_facade() {}
    inline bool empty() const { return container.empty(); }
    inline const_iterator begin() const { return container.begin(); }
    inline const_iterator end() const { return container.end(); }
    inline size_type size() const { return container.size(); }
protected: // hide to force inherited usage only
    readonly_container_facade() {}
protected: // hide assignment by default
    readonly_container_facade(readonly_container_facade const& other):
        : container(other.container) {}
    readonly_container_facade& operator=(readonly_container_facade& other) {
        container = other.container;
        return *this;
    }
protected:
    Container container;
};

template <typename Container>
class writable_container_facade: public readable_container_facade<Container> {
public:
    typedef typename Container::iterator iterator;
    writable_container_facade(writable_container_facade& other)
        readonly_container_facade(other) {}
    virtual ~writable_container_facade() {}
    inline iterator begin() { return container.begin(); }
    inline iterator end() { return container.end(); }
    writable_container_facade& operator=(writable_container_facade& other) {
        readable_container_facade<Container>::operator=(other);
        return *this;
    }
};

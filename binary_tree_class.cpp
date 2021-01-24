//A binary tree class with basic member functions
template<class Item>
class binary_tree_node {
public:
    //define value type
    [[maybe_unused]] typedef Item value_type;

    //construstor
    explicit binary_tree_node(
            const Item &init_data = Item(),
            binary_tree_node *init_left = nullptr,
            binary_tree_node *init_right = nullptr
    ) {
        data_field = init_data;
        left_field = init_left;
        right_field = init_right;
    }

    //modification member function
    Item &data() { return data_field; }

    binary_tree_node *left() { return left_field; }

    binary_tree_node *right() { return right_field; }

    void set_data(const Item &new_data) { data_field = new_data; }

    void set_left(binary_tree_node *new_left) { left_field = new_left; }

    void set_right(binary_tree_node *new_right) { right_field = new_right; }
    //const member functions
    const Item& data() const{return data_field;}
    const binary_tree_node *left()const{return left_field;}
    const binary_tree_node *right()const{return right_field;}
    bool is_leaf()const{return (left_field== nullptr)&&(right_field== nullptr);}

private:
    Item data_field;
    binary_tree_node *left_field;
    binary_tree_node *right_field;
};

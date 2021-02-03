//list
class node {
public:
    typedef double value_type;

    node(
            const value_type &init_data = value_type(),
            node *init_link = nullptr
    ) {
        data_field = init_data;
        link_field = init_link;
    }

    void set_data(const value_type &new_data) {
        data_field = new_data;
    }

    void set_link(node *new_link) {
        link_field = new_link;
    }

    //constent memberfunction to retrieve the current data;
    value_type data() const {
        return data_field;
    }

    //two slightliy different member functions to retrieve the current link
    const node *link() const { return link_field; }

    node *link() { return link_field; };

private:
    value_type data_field;
    node *link_field;
};

void list_insert(node* previous_ptr,const node::value_type& entry){
    node* insert_ptr = new node;
    insert_ptr->set_data(entry);
    insert_ptr->set_link(previous_ptr->link());
    previous_ptr->set_link(insert_ptr);
}

node* list_search(node* head_ptr,const node::value_type& target){
    node* cursor;
    for (cursor=head_ptr;cursor!= nullptr;cursor=cursor->link()){
        if (target==cursor->data()){
            return cursor;
        }
    }
    return nullptr;
}

const node* list_search(const node* head_ptr,const node::value_type& target){
    const node*cursor;
    for (cursor=head_ptr;cursor!= nullptr;cursor=cursor->link()){
        if (target==cursor->data()){
            return cursor;
        }
    }
    return nullptr;
}












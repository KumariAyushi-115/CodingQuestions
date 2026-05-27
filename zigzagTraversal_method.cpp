
vector<vector<int>> zigzag(Node*root){
    vector<vector<int>> res;
    if(root == nullptr) return res;
    
    queue<Node*> q;
    q.push(root);
    
    bool ltr = true;
    while(!q.empty()){
        int levelsize = q.size();
       
        vector<int> vec(levelsize);
        for(int i=0;i<levelsize;i++){
            
             Node*curr=q.front();
            q.pop();
            
            if(ltr){
                vec[i]=curr->val;
            }
            else{
                vec[levelsize - i-1] =  curr->val;
            }
           if(curr->left != nullptr) q.push(curr->left);
           if(curr->right != nullptr) q.push(curr->right);
          
        }
        
        res.push_back(vec);
        ltr = !ltr;
    }
    
    return res;
}

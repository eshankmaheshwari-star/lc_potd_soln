/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* temp=prev->next;
        ListNode* nex=temp->next;
        int maxi=INT_MIN,mini=INT_MAX;
        if(!nex || !temp) return {-1,-1};
        int firstidx=-1,lastidx=-1,cnt=1;
        while(nex!=nullptr){
            int a=prev->val;
            int b=temp->val;
            int c=nex->val;
            cnt++;
            if((a<b && b>c)||(b<a && b<c)){
                if(firstidx!=-1) maxi=cnt-firstidx;
                if(lastidx!=-1) mini=min(mini,cnt-lastidx);
                if(firstidx==-1) firstidx=cnt;
                lastidx=cnt;
            }
            prev=temp;
            temp=nex;
            nex=nex->next;
        }
        if(maxi==INT_MIN && mini==INT_MAX) return {-1,-1};
        return {mini,maxi}; 
    }
};
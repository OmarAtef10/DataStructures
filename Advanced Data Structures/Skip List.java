import java.util.Random;

class Node{
    public Node above;
    public Node below;
    public Node nxt;
    public Node prev;
    public int key;

    public Node(int key){
        this.key=key;
        this.above=null;
        this.below=null;
        this.nxt=null;
        this.prev=null;
    }
}

public class SkipList {
    private Node head;
    private Node tail;

    private final int NEG_INFINITY = Integer.MIN_VALUE;
    private final int POS_INFINITY = Integer.MAX_VALUE;

    private int height = 0;
    public Random random =new Random();

    public SkipList(){
        head = new Node(NEG_INFINITY);
        tail = new Node(POS_INFINITY);
        head.nxt=tail;
        tail.prev=head;
    }

    public Node skipSearch (int key){
        Node n = head;

        while (n.below!=null){
            n=n.below;

            while (key>=n.nxt.key){
                n=n.nxt;
            }
        }
        return n;
    }

    public Node skipInert (int key){
        Node pos = skipSearch(key);
        Node n;
        int lvl = -1;
        int heads = -1;

        if (pos.key==key){
            return pos;
        }else {
            do {
                heads++;
                lvl++;

                increaseLevel(lvl);

                n=pos;
                while (pos.above==null){
                    pos = pos.prev;
                }
                pos = pos.above;

                n = insertAbove(pos , n , key);
            }while (random.nextBoolean() == true);

        }
        return n;
    }

    public Node remove(int key){
        Node removeNode = skipSearch(key);
        if (removeNode.key!=key){
            System.out.println("Node with key "+key+" is not found");
            return null;
        }
        removeReferences(removeNode);

        while (removeNode!=null){
            removeReferences(removeNode);
            if (removeNode.above==null){
                removeNode=removeNode.above;
            }else {
                break;
            }
        }
        return removeNode;
    }

    private void removeReferences(Node removedNode){
        Node afterRemoved = removedNode.nxt;
        Node befRemoved = removedNode.prev;

        befRemoved.nxt=afterRemoved;
        afterRemoved.prev=befRemoved;

    }

    private  void increaseLevel(int lvl) {
        if (lvl >= height){
            height++;
            addEmptyLvl();
        }
    }
    private void addEmptyLvl(){
        Node newHead = new Node(NEG_INFINITY);
        Node newTail = new Node(POS_INFINITY);
        newHead.nxt=newTail;
        newHead.below=head;

        newTail.prev=newHead;
        newTail.below=tail;
        head.above=newHead;
        tail.above=newTail;

        head=newHead;
        tail=newTail;

    }

    private Node insertAbove(Node pos, Node n, int key){
        Node newNode = new Node(key);
        Node nodePrev = pos.below.below;

        setBef_and_After(n,newNode);
        setAbove_and_Below(pos,key,newNode,nodePrev);

        return newNode;
    }

    private void setBef_and_After(Node n , Node newNode){
        newNode.nxt = n.nxt;
        newNode.prev=n;
        n.nxt.prev=newNode;
        n.nxt=newNode;
    }
    private void setAbove_and_Below(Node pos , int key , Node newNode , Node befNewNode){
        if (befNewNode!=null){
            while (true){
                if (befNewNode.nxt.key!=key){
                    befNewNode=befNewNode.nxt;
                }else{
                    break;
                }
            }
            newNode.below=befNewNode.nxt;
            befNewNode.nxt.above=newNode;
        }

        if (pos!=null){
            if (pos.nxt.key==key){
                newNode.above=pos.nxt;
            }
        }
    }

    public void print(){
        StringBuilder s = new StringBuilder();
        s.append("\nSkipList starting from top left node . \n");

        Node start = head;
        Node highestLevel = start;
        int level = height;

        while (highestLevel!=null){
            s.append("\nLevel : " + level +"\n");

            while (start!=null){
                if (start.key== head.key){
                    s.append("Start Node : ");
                }
                else if (start.key== tail.key){
                    s.append("End Node");
                }
                else{
                s.append(start.key);
                if (start.nxt!=null){
                    s.append(" : ");
                }
                }

                start=start.nxt;
            }

            highestLevel=highestLevel.below;
            start=highestLevel;
            level--;
    }

        System.out.println(s.toString() + "\n");
    }



    public static void main(String[] args) {

        SkipList skipList = new SkipList();
        skipList.skipInert(69);
        skipList.skipInert(15);
        skipList.skipInert(420);
        skipList.skipInert(4);

        skipList.print();

        skipList.remove(4);
        skipList.remove(69420);
        skipList.print();

    }
}

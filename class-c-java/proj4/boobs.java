import java.*;
import java.lang.*;
import java.io.*;
//node of the binary tree
class bnode {   
  String key;
  String first;
  String age;
  String id;
  bnode left;
  bnode right;

  bnode() {           
    key = null;
    first = null;
    age = null;
    id = null;
    left = null;
    right = null;
  }

  bnode(String key, String first, String age, String id) {

    this.key = key;
    this.first = first;
    this.age = age;
    this.id = id;
    left = null;
    right = null;
  }
};
   //binary tree
class btree {                
  bnode root;
  btree() {
    root = null;
  }
//insert a node into the tree
  void put(String key, String first, String age, String id) {
    bnode current = root;
    bnode prev = current;
    if (root == null) {
      root = new bnode(key, first, age, id);
    }
    else {
      boolean insert = false;
      while (insert == false) {

        prev = current;
        if (key.compareTo(current.key) < 0) {
          if (current.left == null) {
            current.left = new bnode(key, first, age, id);
            insert = true;
          }
          current = current.left;

        }
        else {
          if (current.right == null) {
            current.right = new bnode(key, first, age, id);
            insert = true;
          }
          current = current.right;
        }

      }

    }

  }
  //delete a node with a key
  boolean delete(String key) {        
    boolean deleted = true;
    bnode current = root;
    bnode prev = current;
    while (current != null) {
      if (key.compareTo(current.key) > 0) {
        prev = current;
        current = current.right;
      }
      else if (key.compareTo(current.key) < 0) {
        prev = current;
        current = current.left;
      }
      else if (key.compareTo(current.key) == 0) {
        deleted = false;
        break;
      }

    }

    if (check(current) == 0) {
      if (current.key.compareTo(prev.key) > 0) {
        prev.right = null;
      }
      else {
        prev.left = null;
      }
    }
    else if (check(current) == 1) {

      if (current.key.compareTo(prev.key) > 0) {
        if (current.left != null) {
          prev.right = current.left;
        }
        else {
          prev.right = current.right;
        }
      }
      else {
        if (current.left != null) {
          prev.left = current.left;
        }
        else {
          prev.left = current.right;
        }
      }
    }
    else if (check(current) == 2) {
      bnode temp = inord(current);
      if (current == root) {
        root.key = temp.key;
        root.first = temp.first;
        root.age = temp.age;
        root.id = temp.id;

      }
      else {
        if (current.key.compareTo(prev.key) > 0) {
          prev.right.key = temp.key;
          prev.right.first = temp.first;
          prev.right.age = temp.age;
          prev.right.id = temp.id;
        }
        else {
          prev.left.key = temp.key;
          prev.left.first = temp.first;
          prev.left.age = temp.age;
          prev.left.id = temp.id;
        }
      }
    }

    return deleted;
  }
//in order
  bnode inord(bnode a) {                    
    int t = 0;
    bnode ret, prev = new bnode();
    prev = a;
    a = a.right;
    while (a.left != null) {
      prev = a;
      a = a.left;
      t = 1;
    }
    ret = a;
    if (t == 0) {
      prev.right = null;
    }
    else {
      prev.left = null;
    }
    a = null;
    return ret;
  }
//check if a node is there
  int check(bnode a) { 
    int ret;
    if ( (a.left != null) && (a.right != null)) {
      ret = 2;
    }
    else if ( (a.left == null) && (a.right == null)) {
      ret = 0;
    }
    else {
      ret = 1;
    }
    return ret;
  }
//print the node
  void printIn(bnode oot) {                  
    if (oot.left != null) {
      printIn(oot.left);
    }
    System.out.println(oot.key + ", " + oot.first + " - " + oot.age + " - " + oot.id );
    if (oot.right != null) {
      printIn(oot.right);
    }
  }
  void search(bnode oot, String key) {                  
	    if(key.equals(oot.key)) {
	    	System.out.println(oot.key + ", " + oot.first + " - " + oot.age + " - " + oot.id );
	    }
	    else {
	    	if (oot.left != null) {
	  	      search(oot.left, key);
	  	    }
	  	    //System.out.println(oot.key + ", " + oot.first + " - " + oot.age + " - " + oot.id );
	  	    if (oot.right != null) {
	  	      search(oot.right, key);
	  	    }
	    }
	  	
	  }

  public static void main(String[] args) {

    btree a = new btree();
    BufferedReader i = new BufferedReader(new InputStreamReader(System.in));
    while(true) {
    	//System.out.println("Input value: ");
    	int choice = 1;
    	System.out.println("Pick one:\n1. Print All\n2. Insert\n3. Search\n4. Delete");
    	String text = "a", first = "a", age = "a", id = "a";
    	try {
    		choice = Integer.parseInt(i.readLine());
    	}
    	catch (IOException ioex) {
    		System.out.println("FFFFFUUUUUUUUUU");
    	}
    	switch(choice) {
    	case 1:
    		a.printIn(a.root);
    		break;
    		
    	case 2:
    		
        	try {
        		System.out.println("Last name:");
        		text = i.readLine();
        		System.out.println("First name:");
        		first = i.readLine();
        		System.out.println("Age:");
        		age = i.readLine();
        		System.out.println("ID:");
        		id = i.readLine();
        		
        		
        	}
        	catch (IOException ioex) {
        		System.out.println("FFFFFUUUUUUUUUU");
        	}
        	a.put(text, first, age, id);
        	
        	break;
    	case 3:
    		try{
    			System.out.println("Enter last name:");
    			text = i.readLine();
    			a.search(a.root, text);
    			
    		}
    		catch (IOException ioex) {
        		System.out.println("FFFFFUUUUUUUUUU");
        	}
    		break;
    	case 4:
    		try{
    			System.out.println("Enter last name:");
    			text = i.readLine();
    			a.delete(text);
    			
    		}
    		catch (IOException ioex) {
        		System.out.println("FFFFFUUUUUUUUUU");
        	}
    	}
    	
    	
    	//a.printIn(a.root);
    	
    }

    //a.printIn(a.root);
  }
}


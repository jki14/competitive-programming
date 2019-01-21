import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Student{
	private int token;
	private String fname;
	private double cgpa;
	public Student(int token, String fname, double cgpa) {
		super();
		this.token = token;
		this.fname = fname;
		this.cgpa = cgpa;
	}
	public int getToken() {
		return token;
	}
	public String getFname() {
		return fname;
	}
	public double getCgpa() {
		return cgpa;
	}
}

class StudentComparator implements Comparator<Student>{
	 @Override
	 public int compare(Student lhs, Student rhs){
	 	double dCgpa=lhs.getCgpa()-rhs.getCgpa();
		  if(Math.abs(dCgpa)<1e-6){
		  	int dFname=lhs.getFname().compareTo(rhs.getFname());
		  	if(dFname==0){
		  		return lhs.getToken()-rhs.getToken();
		  	}else return dFname;
		  }else return (dCgpa<0.0)?1:-1;
	 }
}

class Core{
	Queue<Student> studentPQ = new PriorityQueue<Student>(1, new StudentComparator());
	public void enter(int token, String fname, double cgpa){
		studentPQ.add(new Student(token, fname, cgpa));
	}
	public void served(){
		studentPQ.poll();
	}
	public void  printRemain(){
		if(studentPQ.isEmpty()){
			System.out.println("EMPTY");
		}else{
			while(!studentPQ.isEmpty()){
				Student cur=studentPQ.poll();
				System.out.println(cur.getFname());
			}
		}
	}
}

public class Solution {
	public static void main(String[] args) {
		Core core = new Core();
		Scanner in = new Scanner(System.in);
		int totalEvents = Integer.parseInt(in.nextLine());
		while(totalEvents>0){
			String event = in.next();
			if(event.equals("ENTER")){
				String fname = in.next();
				double cgpa = in.nextDouble();
				int token = in.nextInt();
				core.enter(token, fname, cgpa);
			}else{
				core.served();
			}
			totalEvents--;
		}
		core.printRemain();
	}
}
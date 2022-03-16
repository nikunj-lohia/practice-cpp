package com.company;
import java.util.*;
import java.io.File;
import java.util.Scanner;

class Shape {

    protected double breadth;
    protected double length;
    public Shape(double l, double b) {
        length = l;
        breadth = b;
    }

    public double area() {
        return (double)length * breadth;
    }
}

class Circle extends Shape {

    Circle(double length, double breadth) {
        super(length, breadth);
    }
    public double area() {
        return  (Math.PI) * Math.pow(length, 2);
    }
    public void display() {
        System.out.println("A Circle of radius " + length + "is created.");
    }
}

class Rectangle extends Shape {

    Rectangle(double length, double breadth) {
        super(length, breadth);
    }

    public double area() {
        return (double)length * breadth;
    }
    public void display() {
        System.out.println("A  Rectangle with length " + length + " and breath " + breadth + "is created.");
    }
}

class Trapezoid extends Shape {
    double height;
    Trapezoid(double length, double breadth, double height) {
        super(length, breadth);
        this.height = height;
    }

    public double area() {
        return (double)(0.5 * (length + breadth) * height);
    }
    public void display() {
        System.out.println("A Trapezoid of parellel sides of lengths : " + length + " " + breadth + " and  height " + height + "is created ");
    }
}

public class Main {
    public static void main(String[] args) {
        //input manually given
        Trapezoid trapezoid = new Trapezoid(4, 5, 4);
        Rectangle rectangle = new Rectangle(4, 5);
        Circle circle = new Circle(3, 3);
        System.out.println("Area of Circle " + circle.area());
        System.out.println("Area of Rectangle " + rectangle.area());
        System.out.println("Area of Trapezoid " + trapezoid.area());
    }
}
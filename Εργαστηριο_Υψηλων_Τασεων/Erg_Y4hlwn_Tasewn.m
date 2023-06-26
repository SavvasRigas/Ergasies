clear all;
close all;
clc;

Metrhseis = csvread('tek00011.csv');
t = Metrhseis(:,1);
V = Metrhseis(:,2);

plot(t,V)
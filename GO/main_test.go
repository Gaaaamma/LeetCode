package main

import (
	"gaaaamma/list"
	"gaaaamma/medium"
	"testing"
)

func TestCase1(t *testing.T) {
	get := medium.PairSum(list.CreateList([]int{5, 4, 2, 1}))
	want := 6
	if get != want {
		t.Errorf("Not equal %v != %v\n", get, want)
	}
}

func TestCase2(t *testing.T) {
	get := medium.PairSum(list.CreateList([]int{4, 2, 2, 3}))
	want := 7
	if get != want {
		t.Errorf("Not equal %v != %v\n", get, want)
	}
}

func TestCase3(t *testing.T) {
	get := medium.PairSum(list.CreateList([]int{1, 100000}))
	want := 100001
	if get != want {
		t.Errorf("Not equal %v != %v\n", get, want)
	}
}

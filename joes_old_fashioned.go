/*
 *  joes_old_fashioned - Joe has a "whiskey ball" ice cube
 *                       in a tumbler that is full of
 *                       his favorite bourbon. The tumbler
 *                       is 80 mm high with a diameter of 70 mm.
 *                       The radius of the ice whiskey ball is 33mm.
 *                       What is the volume of the whiskey in 
 *                       this delightful and refreshing beverage?
 *
 */

package main

import (
	"fmt"
	"math"
)

func main() {
	var sphereRadius = 33.0
	var cylinderRadius = 35.0
	var cylinderHeight = 80.0

 	fmt.Printf("sphere   radius: %.3f\n", sphereRadius)
 	fmt.Printf("cylinder radius: %.3f\n", cylinderRadius)
 	fmt.Printf("cylinder height: %.3f\n", cylinderHeight)

	var s = sphereVolume(sphereRadius)
	var c = cylinderVolume(cylinderRadius, cylinderHeight)
	
	fmt.Printf("Volume of sphere: %.3f\n", s)
	fmt.Printf("Volume of cylinder: %.3f\n", c)

	var whiskeyVolume = c - s
	fmt.Printf("Volume of Joe's whiskey: %.3f\n", whiskeyVolume)
	fmt.Printf("Volume of Joe's whiskey (in liters): %.3f\n", cubicCentimetersToLiters(whiskeyVolume))
}

func cubicCentimetersToLiters(n float64) (float64) {
	return n / 1000.0
}

func sphereVolume(r float64) (float64) {
	return (4/3) * math.Pi * (r*r*r)
}

func cylinderVolume(r float64, h float64) (float64) {
	return math.Pi * (r*r) * h
}

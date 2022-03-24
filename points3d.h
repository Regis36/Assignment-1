// --> Regis Enama
// Few comments describing the class Points3D

#ifndef CSCI335_HOMEWORK1_POINTS3D_H_
#define CSCI335_HOMEWORK1_POINTS3D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points3D {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  // Set size to 0.
//set sequene to null
    Points3D(): size_ {0} , sequence_ {nullptr}
    {}//works

  // Copy-constructor.
  Points3D(const Points3D &rhs)
    {
        size_ = rhs.size_ ;
        //create a new array
        sequence_ = new std::array<Object, 3> [size_ ];
        
        //loop through the rhs sequence and then copy it into sequence
        for (size_t i = 0; i < rhs.size_ ; i++)
        {
            sequence_[i] = rhs.sequence_[i];
        }
    }//works

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points3D copy = rhs;
  // std::swap(*this, copy);
  // return *this;
  // }
    Points3D& operator=(const Points3D &rhs)
    {
        Points3D copy = rhs;
        std::swap(*this, copy);
        return *this;
    }//works

  // Move-constructor.
    Points3D(Points3D &&rhs)
    {
        size_ = rhs.size_ ;
        rhs.size_ = 0;
        
        sequence_ = rhs.sequence_;
        rhs.sequence_ = nullptr;
    }//works

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points3D& operator=(Points3D &&rhs)
    {
        std::swap( size_ , rhs.size_);
        std::swap( sequence_ , rhs.sequence_);
        
        return *this; 
    }//works
    

    ~Points3D()
    {
        delete [] sequence_;
        sequence_ = nullptr;
    }//works

  // End of big-five.

  // One parameter constructor.
  Points3D(const std::array<Object, 3>& item) {
      //set the size to item's size;
      size_ = 1 ;
      
      //create a new array and have sequence_ point at it
      sequence_ = new std::array<Object,3> (item);
      
  } //works

  size_t size() const {
      return size_ ; 
  } //works

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 3>& operator[](size_t location) const
    {
        if ( location >= size_)
        {
            std::abort();
        }
      
        return sequence_ [location];
  }//works

  //  @c1: A sequence.
  //  @c2: A second sequence.
  //  @return their sum. If the sequences are not of the same size, append the
  //    result with the remaining part of the larger sequence.
  friend Points3D operator+(const Points3D &c1, const Points3D &c2) {
   //just adding two arrays
  }

  // Overloading the << operator.
  friend std::ostream &operator<<(std::ostream &out, const Points3D &some_points) {
    //check if its empty
      if(some_points.size_ == 0)
      {
          //if empty, do nothing, throw an error message
          out << "( )" ;
      }
      
      for(size_t i = 0; i < some_points.size_ ; i++)
      {
              out << "(";
              out << some_points.sequence_[i][0] ;
              out << ", " ;
              out <<  some_points.sequence_[i][1] ;
              out << ", " ;
              out <<some_points.sequence_[i][2];
              out << ")" << " "; 
      }
      out << std::endl;
      return out;
  }//works

  // Overloading the >> operator.
  // Read a chain from an input stream (e.g., standard input).
  friend std::istream &operator>>(std::istream &in, Points3D &some_points) {
    //deallocate some_points.sequence_
      if (some_points.sequence_ != nullptr)
      {
          delete some_points.sequence_ ;
          some_points.sequence_ = nullptr ;
      }
      
    //Get size of the Points3d sequence_
      in >> some_points.size_;
      some_points.sequence_ = new std::array<Object,3>[some_points.size_] ;
      
    //populate the sequence_
      for (size_t i = 0; i < some_points.size_ ; i++)
      {
          for (size_t j = 0; j < 3 ; j++)
          {
              in >> some_points.sequence_ [i][j];
          }
      }
      
      return in;
  } //works

 private:
  // Sequence of points.
  std::array<Object, 3> *sequence_;
  // Size of sequence.
  size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS3D_H_

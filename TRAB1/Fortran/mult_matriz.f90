PROGRAM Main
  use, intrinsic :: iso_fortran_env, only: dp=>real64
  implicit none

  real                      :: u, startB, finishB, startC, finishC
  integer                   :: i, j
  integer, parameter        :: n = 1000
  real(dp), dimension (n,n)     :: A
  real(dp), dimension (n)     :: x, b, b2
  logical                   :: printMatrixs = .false. ! Change the value in order to print the matrices


function matrix_lenght(rambg) result(x)
  implicit none
  integer, intent(in) :: ramgb
  !integer :: a
  !integer :: b
  real(dp) :: max_
  real(dp) :: c
  real(dp) :: delta
  real(dp) :: x
  real(dp) :: x1
  real(dp) :: x2
  max_ = rambg*(10**9)*8 
  c = -1*max_/64
  !a = 1
  !b = 2
 
  delta = (2**2) - 4*1*c
  if(delta >= 0) then
    if(delta == 0) then
      x1 = -2 / (2 * 1)
      !printf("Tamanho máximo dos arrays: %d\n",(int) floor(x1));
      x=x1
      end function matrix_lenght
      end if
    x1 = (-2 - sqrt(delta)) / (2 * 1)
    x2 = (-2 + sqrt(delta)) / (2 * 1)
    if(x1>x2) then
      !printf("Tamanho máximo dos arrays: %d\n",(int) floor(x1));
      x=x1
      end function matrix_lenght
    end if
    !printf("Tamanho máximo dos arrays: %d\n",(int) floor(x2));
    x=x2
    end function matrix_lenght
      
  end function matrix_lenght


  ! ------------------------------------------------------ Matrix A
  do i = 1, n
    do j = 1, n
      call random_number(u)
      A(i,j) = u
    end do
  end do

  if(printMatrixs) then
    print*, ""
    print*, "Matriz A:"
    do i = 1, n
      print*, A(i,:)
    end do
  end if



  ! ------------------------------------------------------ Matrix x
  do i = 1, n
    call random_number(u)
    x(i) = u
  end do
  
  if(printMatrixs) then
    print*, ""
    print*, "Matriz x:"
    do i = 1, n
      print*, x(i)
    end do
  end if



  ! ------------------------------------------------------ Matrix b
  b = 0.0
  call cpu_time(startB)
  do i = 1, n
    do j = 1, n
      b(i) = b(i) + A(i,j) * x(j)
    end do
  end do
  call cpu_time(finishB)

  if(printMatrixs) then
    print*, ""
    print*, "Matriz b:"
    do i = 1, n
      print*, b(i)
    end do
  end if



  ! ------------------------------------------------------ Matrix c
  b2 = 0.0
  call cpu_time(startC)
  do j = 1, n
    do i = 1, n
      b(i) = b(i) + A(i,j) * x(j)
    end do
  end do
  call cpu_time(finishC)


  if(printMatrixs) then
    print*, ""
    print*, "Matriz c:"
    do i = 1, n
      print*, b2(i)
    end do
  end if



  ! ------------------------------------------------------ Results time
  print '(I0, ",", f10.6, ",", f10.6)', n, finishB - startB, finishC - startC

END PROGRAM Main
PROGRAM Main
  use, intrinsic :: iso_fortran_env, only: dp=>real64
  implicit none
  real                      :: u, startB, finishB, startC, finishC
  integer                   :: i, j
  integer, parameter        :: n = 100
  real(dp), dimension (n,n)     :: A
  real(dp), dimension (n)     :: x, b, b2
  real(dp) :: matrix_lenght_r
  CHARACTER(len=32) :: arg
  real(dp) :: intl


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
  !print '(I0, ",", f10.6, ",", f10.6)', n, finishB - startB, finishC - startC
  
  DO i = 1,3
    CALL get_command_argument(i, arg)
    IF (LEN_TRIM(arg) == 0) EXIT
    !WRITE (*,*) TRIM(arg)
    print*,arg
    read( arg, '(d10.0)' )  intl
    matrix_lenght_r = matrix_lenght(floor(intl))
    print*, "ok"
    print *,floor(matrix_lenght_r)
  END DO


contains
  
  real(dp) function matrix_lenght(ramgb)
    implicit none
    !integer :: ramgb
    real(dp) :: c
    real :: a, b
    real :: discriminant
    real :: x1, x2
    integer :: ramgb
    integer :: i

    a = 1
    b = 2
    matrix_lenght = 0
    
    !print *,ramgb(i)*8/64*1000000000*(-1) !!!!problema aqui!!!!
    c = ramgb*8
    c = c/64*(-1)
    c = c*1000000000   
    !print *,c
    discriminant = b**2 - 4*a*c
    !print *,discriminant
    !print *,sqrt(discriminant)
    
    if ( discriminant>0 ) then
    
      x1 = ( -b + sqrt(discriminant)) / (2 * a)
      x2 = ( -b - sqrt(discriminant)) / (2 * a)
      if (x1>x2) then
        matrix_lenght = x1
      else if (x2>x1) then
        matrix_lenght = x2
      end if
    else if ( discriminant==0 ) then
      x1 = - b / (2 * a)
      matrix_lenght = x1
    end if
  end function matrix_lenght
END PROGRAM Main
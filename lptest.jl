## include("lptest.jl")
## lptest("problem-00003-00003-00000a.txt")

# using Printf
using JuMP
using Clp

function lptest(filename)
    lines = open(filename, "r") do fp
        readlines(fp)
    end

    m = parse(Int, lines[1])
    n = parse(Int, lines[2])

    b = parse.(Float64, (split(lines[3],[','])))
    c = parse.(Float64, (split(lines[4],[','])))
    A = zeros(Float64, m, n)
    for i=1:m
        A[i,:] = parse.(Float64, (split(lines[4+i],[','])))
    end

    # @show b
    # @show c
    # @show A

    before_solve = time()
    model1 = Model(Clp.Optimizer)
    @variable(model1, x[1:n]>=0)
    @objective(model1, Max, dot(c, x))
    @constraint(model1, A*x .<= b)
    optimize!(model1)
    time_solve = time() - before_solve
    status = termination_status(model1)
    x_value = value.(x)

    @show x_value
    @show status
    @show time_solve
end

    

classdef individual
    %individual class. An individual is a single member of a population
    
    properties
        route = [1,2,3,4,5,6,7,8,9,10]; %this is the array containing the route taken between cities.
        fitness; %this is the fitness of the individual  
    end
    
    methods 
        
        %constructor method
        function obj = individual(World)
            %This constructor builds an individual
            x = size(World);
            x = x(1);
            obj.route = 1:1:x;
            
            obj = randomise(obj);%call randomise method upon construction
            
            obj = determineFitness(obj,World);%call determimeFitness method upon construction
        end
        
        %set route
        function obj = set.route(obj, Value)
            %set the value of route with a 1x10 vector
            checkSize = size(Value);
            if (checkSize(1) == 1) && (checkSize(2) > 1)
                obj.route=Value;
            else
                error('invalid route');
            end
        end
        
        %randomise route
        function obj = randomise(obj)
            %randomise order of cities visited
            obj.route = obj.route(randperm(length(obj.route))); 
        end
        
        %set fitness
        function obj = set.fitness(obj, Value)
            %set the value of fitness with a scalar value
            if isscalar(Value)
                obj.fitness=Value;
            else
                error('invalid fitness');
            end
        end
        
        %Evaluate fitness
        function obj = determineFitness(obj, World)
            fitnessCheck = 0;
            %evaluate the distance between city i and city i+1, 9 times
            for count=1:9
                city1 = obj.route(count);
                city2 = obj.route(count+1);
                city1 = World(city1,:);
                city2 = World(city2,:);
                distance = sqrt((city1(1)-city2(1))^2+(city1(2)-city2(2))^2);
                fitnessCheck = fitnessCheck+distance;
            end
            obj.fitness = fitnessCheck;
        end 
    end
end
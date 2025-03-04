
```ad-info
title: Definition
- A **design pattern** used in software development to **manage transactions and the overall coordination of data access operations**
- In UoW, a set of related operations needs to be **treated as a single unit**

```

# Purposes

- Co-ordinate multiple operations that needs to be **treated as a single logical unit**
- Manages the transactional behavior, ensuring that all changes are committed or rolled back atomically.

# Components

- UoW interface/class
- Repositories
- Entities

# Benefits

- Consistency
- Isolation
- Transaction management

```csharp
using System;
using System.Collections.Generic;

// Entity representing a simple blog post
public class BlogPost
{
    public int Id { get; set; }
    public string Title { get; set; }
    public string Content { get; set; }
}

// Repository interface for managing BlogPost entities
public interface IBlogPostRepository
{
    BlogPost GetById(int id);
    void Add(BlogPost post);
    void Update(BlogPost post);
    void Delete(int id);
}

// Unit of Work interface
public interface IUnitOfWork : IDisposable
{
    IBlogPostRepository BlogPostRepository { get; }
    void Commit();
    void Rollback();
}

// Concrete implementation of the Unit of Work
public class UnitOfWork : IUnitOfWork
{
    private readonly List<BlogPost> addedPosts = new List<BlogPost>();
    private readonly List<BlogPost> updatedPosts = new List<BlogPost>();
    private readonly List<int> deletedPostIds = new List<int>();

    public IBlogPostRepository BlogPostRepository { get; }

    public UnitOfWork(IBlogPostRepository blogPostRepository)
    {
        BlogPostRepository = blogPostRepository;
    }

    public void Commit()
    {
        // In a real-world scenario, this is where you would persist changes to the database.
        // For simplicity, we'll just print the changes in this example.

        foreach (var post in addedPosts)
        {
            Console.WriteLine($"Added: {post.Title}");
        }

        foreach (var post in updatedPosts)
        {
            Console.WriteLine($"Updated: {post.Title}");
        }

        foreach (var postId in deletedPostIds)
        {
            Console.WriteLine($"Deleted: Post with ID {postId}");
        }
    }

    public void Rollback()
    {
        // In a real-world scenario, you might need to undo any changes made during the unit of work.
        Console.WriteLine("Rolling back changes (not implemented in this example).");
    }

    public void Dispose()
    {
        // Implement IDisposable if needed
    }
}

// Concrete implementation of the BlogPostRepository
public class BlogPostRepository : IBlogPostRepository
{
    // In a real-world scenario, this is where you would interact with a database.
    // For simplicity, we'll just use an in-memory list in this example.
    private readonly List<BlogPost> posts = new List<BlogPost>();

    public BlogPost GetById(int id)
    {
        return posts.FirstOrDefault(post => post.Id == id);
    }

    public void Add(BlogPost post)
    {
        posts.Add(post);
    }

    public void Update(BlogPost post)
    {
        // In a real-world scenario, you might need to implement logic to update the post.
        // For simplicity, we'll just mark it as updated.
    }

    public void Delete(int id)
    {
        // In a real-world scenario, you might need to implement logic to delete the post.
        // For simplicity, we'll just mark the ID for deletion.
    }
}

class Program
{
    static void Main()
    {
        // Creating instances of the repository and unit of work
        IBlogPostRepository blogPostRepository = new BlogPostRepository();
        IUnitOfWork unitOfWork = new UnitOfWork(blogPostRepository);

        // Performing operations within a unit of work
        using (var uow = unitOfWork)
        {
            var post1 = new BlogPost { Id = 1, Title = "First Post", Content = "Content of the first post." };
            var post2 = new BlogPost { Id = 2, Title = "Second Post", Content = "Content of the second post." };

            uow.BlogPostRepository.Add(post1);
            uow.BlogPostRepository.Update(post2);
            uow.BlogPostRepository.Delete(3); // Non-existent post

            uow.Commit(); // Commit changes
        }
    }
}

```
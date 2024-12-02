using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

public class AIImage
{
    public AIImage()
    {
        Prompt = "";
        ImageGenerator = "";
        Filename = "";
    }

    [Required]
    public int Id { get; set; }

    [Required]
    public string Prompt { get; set; }

    [Required]
    [Display(Name = "Image Generator")]
    public string ImageGenerator { get; set; }

    [Display(Name = "Upload Date")]
    public DateTime UploadDate { get; set; }

    public string Filename { get; set; }

    public int Like { get; set; }

    public bool canIncreaseLike { get; set; }

    [NotMapped]
    public IFormFile UploadedFile { get; set; }
}

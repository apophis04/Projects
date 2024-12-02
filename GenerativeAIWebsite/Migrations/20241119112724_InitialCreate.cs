using System;
using Microsoft.EntityFrameworkCore.Migrations;

#nullable disable

namespace GenerativeAIWebsite.Migrations
{
    /// <inheritdoc />
    public partial class InitialCreate : Migration
    {
        /// <inheritdoc />
        protected override void Up(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.CreateTable(
                name: "AIImages",
                columns: table => new
                {
                    Id = table.Column<int>(type: "int", nullable: false)
                        .Annotation("SqlServer:Identity", "1, 1"),
                    Prompt = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    ImageGenerator = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    UploadDate = table.Column<DateTime>(type: "datetime2", nullable: false),
                    Filename = table.Column<string>(type: "nvarchar(max)", nullable: false),
                    Like = table.Column<int>(type: "int", nullable: false),
                    canIncreaseLike = table.Column<bool>(type: "bit", nullable: false)
                },
                constraints: table =>
                {
                    table.PrimaryKey("PK_AIImages", x => x.Id);
                });
        }

        /// <inheritdoc />
        protected override void Down(MigrationBuilder migrationBuilder)
        {
            migrationBuilder.DropTable(
                name: "AIImages");
        }
    }
}
